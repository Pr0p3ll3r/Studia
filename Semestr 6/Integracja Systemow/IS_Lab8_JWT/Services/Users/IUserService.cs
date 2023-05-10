using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using IS_Lab8.Entities;
using IS_Lab8.Model;

namespace IS_Lab8.Services.Users
{
    public interface IUserService
    {
        AuthenticationResponse
        Authenticate(AuthenticationRequest request);
        IEnumerable<User> GetUsers();
        User GetByUsername(string username);
        User GetById(int id);
    }
}
