using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;

namespace IS_Lab8.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class NumbersController : ControllerBase
    {
        public NumbersController()
        {       
        }
        [HttpGet("random")]
        [Authorize(Roles = "number", AuthenticationSchemes = JwtBearerDefaults.AuthenticationScheme)]
        public IActionResult GetUsers()
        {
            int[] primes = { 2, 3, 5, 7, 11, 13 };
            var random = new Random();
            int randomNumber = primes[random.Next(primes.Length)];
            return Ok(randomNumber);
        }
    }
}
