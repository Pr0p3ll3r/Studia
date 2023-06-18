import { useState } from "react"
import axios from "axios"
import { Link, useNavigate } from "react-router-dom"

const Register = () => {
  const [data, setData] = useState({
    name: "",
    email: "",
    phoneNumber: "",
    password: "",
    confirmPassword: "",
  })
  const [error, setError] = useState("")
  const navigate = useNavigate()
  const handleChange = ({ currentTarget: input }) => {
    setData({ ...data, [input.name]: input.value })
  }

  const handleSubmit = async (e) => {
    e.preventDefault()

    if (data.password !== data.confirmPassword) {
      setError("Hasła nie pasują");
      return
    }

    try {
      const { data: res } = await axios.post("http://localhost:8080/api/user/register", data)
      navigate("/login")
      console.log(res.message)
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
                  <h1 className="text-uppercase">Rejestracja</h1>
                  <div className="mt-4">
                    <input
                      type="text"
                      placeholder="Imię"
                      name="name"
                      onChange={handleChange}
                      value={data.name}
                      required
                      pattern="[A-Za-z]+"
                      title="Nazwa może zawierać tylko litery"
                      className="block mt-1 w-full form-control"
                    />
                  </div>
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
                      type="text"
                      placeholder="Numer telefonu"
                      name="phoneNumber"
                      onChange={handleChange}
                      value={data.phoneNumber}
                      required
                      pattern="[0-9]{9}"
                      maxLength={9}
                      title="Numer telefonu musi mieć 9 cyfr"
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
                      pattern="(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*_=+-]).{8,26}"
                      title="Hasło musi zawierać od 8 do 26 znaków, w tym 1 małą literę, 1 wielką literę, 1 cyfrę i 1 znak specjalny"
                      className="block mt-1 w-full form-control"
                    />
                  </div>
                  <div className="mt-4">
                    <input
                      type="password"
                      placeholder="Powtórz hasło"
                      name="confirmPassword"
                      onChange={handleChange}
                      value={data.confirmPassword}
                      required
                      className="block mt-1 w-full form-control"
                    />
                  </div>
                  <div className="flex justify-content-center mt-4">
                    <Link to="/login" className="p-2">
                      Logowanie
                    </Link>
                    <button className="px-4 py-2 btn btn-primary">Zarejestruj się</button>   
                    {error && <div
                      className="mt-2 p-lg-0 text-sm text-danger space-y-1">{error}</div>}
                  </div>
                </form>
              </div>
            </div>
          </div>
        </div>
      </div >
    </div >
  )
}

export default Register