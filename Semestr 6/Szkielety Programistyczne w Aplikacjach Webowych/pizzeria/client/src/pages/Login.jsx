import { useState } from "react"
import axios from "axios"
import { Link } from "react-router-dom"

const Login = () => {
  const [data, setData] = useState({ email: "", password: "" })
  const [error, setError] = useState("")
  const handleChange = ({ currentTarget: input }) => {
    setData({ ...data, [input.name]: input.value })
  }

  const handleSubmit = async (e) => {
    e.preventDefault()
    try {
      const { data: res } = await axios.post("http://localhost:8080/api/user/login", data)
      localStorage.setItem("token", res.data)
      window.location = "/profile"
    } catch (error) {
      if (
        error.response &&
        error.response.status >= 400 &&
        error.response.status <= 500
      ) {
        setError(error.response.data.message)
      }
    }
  }
  
  return (
    <div>
      <div className="page-section cta">
        <div className="container">
          <div className="row">
            <div className="col-xl-9 mx-auto">
              <div className="cta-inner bg-faded text-center rounded">
                <form onSubmit={handleSubmit}>
                  <h1 className="text-uppercase">Logowanie</h1>
                  <div className="mt-4">
                    <input
                      type="email"
                      placeholder="Email"
                      name="email"
                      onChange={handleChange}
                      value={data.email}
                      required
                      className="block mt-1 w-full form-control"
                    />
                  </div>
                  <div className="mt-4">
                    <input
                      type="password"
                      placeholder="Hasło"
                      name="password"
                      onChange={handleChange}
                      value={data.password}
                      required
                      className="block mt-1 w-full form-control"
                    />
                  </div>
                  <div className="flex justify-content-center mt-4">
                    <Link to="/register" className="p-2">
                      Rejestracja
                    </Link>
                    <button className="px-4 py-2 btn btn-primary">Zaloguj się</button>      
                    {error && <div
                      className="mt-2 p-lg-0 text-sm text-danger space-y-1">{error}</div>}
                  </div>
                </form>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  )
}

export default Login;
