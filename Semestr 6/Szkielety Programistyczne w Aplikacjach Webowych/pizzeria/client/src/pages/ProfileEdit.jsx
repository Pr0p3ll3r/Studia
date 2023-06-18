import React from 'react'
import { useState, useEffect } from 'react'
import Modal from 'react-modal'
import axios from "axios"

const ProfileEdit = () => {
  const [modalIsOpen, setIsOpen] = useState(false)
  const [errorModal, setErrorModal] = useState("")

  function openModal() {
    setIsOpen(true)
    document.body.style.overflow = "hidden"
  }

  function closeModal() {
    setIsOpen(false)
    document.body.style.overflow = "auto"
  }

  const removeAccount = async (e) => {
    e.preventDefault()

    const password = e.target.password.value
    const token = localStorage.getItem('token')

    try {
      const response = await axios.delete("http://localhost:8080/api/user", {
        headers: {
          Authorization: `Bearer ${token}`,
        },
        data: {
          password: password
        }
      })

      console.log(response.data.message)
      localStorage.clear()
      closeModal()
      window.location.reload()
    } catch (error) {
      if (
        error.response &&
        error.response.status >= 400 &&
        error.response.status <= 500
      ) {
        setErrorModal(error.response.data.message)
      }
    }
  }

  const [data, setData] = useState({
    userId: "",
    name: "",
    email: "",
    phoneNumber: "",
    currentPassword: "",
    newPassword: "",
    confirmPassword: "",
  })

  const handleChange = ({ currentTarget: input }) => {
    setData({ ...data, [input.name]: input.value })
  }
  const [errorPassword, setErrorPassword] = useState("")
  const [errorInfo, setErrorInfo] = useState("")

  useEffect(() => {
    fetchUser()
  }, [])

  const fetchUser = async () => {
    try {
      const token = localStorage.getItem('token')
      const response = await axios.get('http://localhost:8080/api/user', {
        headers: {
          Authorization: `Bearer ${token}`,
        },
      })

      const userData = response.data.user

      setData({
        userId: userData._id,
        name: userData.name,
        email: userData.email,
        phoneNumber: userData.phoneNumber,
        currentPassword: "",
        newPassword: "",
        confirmPassword: "",
      })
    } catch (error) {
      console.error('Błąd podczas pobierania użytkownika:', error)
    }
  }

  const changePassword = async (e) => {
    e.preventDefault()

    //console.log(data)

    if (data.newPassword === data.currentPassword) {
      setErrorPassword("Hasło jest takie samo jak aktualne");
      return
    }

    if (data.newPassword !== data.confirmPassword) {
      setErrorPassword("Hasła nie pasują");
      return
    }

    try {
      const { data: res } = await axios.post("http://localhost:8080/api/user/change-password", data)
      window.location.reload()
      console.log(res.message)
    } catch (error) {
      if (
        error.response &&
        error.response.status >= 400 &&
        error.response.status <= 500
      ) {
        setErrorPassword(error.response.data.message)
      }
    }
  }

  const changeInfo = async (e) => {
    e.preventDefault()

    //console.log(data)

    try {
      const { data: res } = await axios.post("http://localhost:8080/api/user/change-info", data)
      window.location.reload()
      console.log(res.message)
    } catch (error) {
      if (  
        error.response &&
        error.response.status >= 400 &&
        error.response.status <= 500
      ) {
        setErrorInfo(error.response.data.message)
      }
    }
  }

  return (
    <div className="py-12">
      <section className="page-section cta">
        <div className="container space-y-6">
          <div className="row">
            <div className="col-xl-9 mx-auto">
              <div className="cta-inner bg-faded text-center rounded">
                <div>
                  <header>
                    <h2 className="text-lg font-medium text-gray-900 dark:text-gray-100 fw-bold">
                      Informacje o profilu
                    </h2>
                    <p className="mt-1 text-sm text-gray-600 dark:text-gray-400">
                      Zmień informacje o profilu
                    </p>
                  </header>
                  <form onSubmit={changeInfo} className="mt-6 space-y-6">
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
                    <div className="flex justify-content-center mt-4">
                      <button className='btn btn-primary'>Zapisz</button>
                    </div>
                    {errorInfo && <div
                      className="mt-2 p-lg-0 text-sm text-danger space-y-1">{errorInfo}</div>}
                  </form>
                </div>
              </div>
            </div>
          </div>
          <div className="row">
            <div className="col-xl-9 mx-auto">
              <div className="cta-inner bg-faded text-center rounded">
                <div>
                  <header>
                    <h2 className="text-lg font-medium text-gray-900 dark:text-gray-100 fw-bold">
                      Zmień hasło
                    </h2>
                  </header>
                  <form onSubmit={changePassword} className="mt-6 space-y-6">
                    <div className="mt-4">
                      <input
                        type="password"
                        placeholder="Aktualne hasło"
                        name="currentPassword"
                        onChange={handleChange}
                        value={data.currentPassword}
                        autoComplete=''
                        className="block mt-1 w-full form-control"
                      />
                    </div>
                    <div className="mt-4">
                      <input
                        type="password"
                        placeholder="Nowe hasło"
                        name="newPassword"
                        onChange={handleChange}
                        value={data.newPassword}
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
                        pattern="(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*_=+-]).{8,26}"
                        title="Hasło musi zawierać od 8 do 26 znaków, w tym 1 małą literę, 1 wielką literę, 1 cyfrę i 1 znak specjalny"
                        className="block mt-1 w-full form-control"
                      />
                    </div>
                    <div className="flex justify-content-center mt-4">
                      <button className='btn btn-primary'>Zapisz</button>
                    </div>
                    {errorPassword && <div
                      className="mt-2 p-lg-0 text-sm text-danger space-y-1">{errorPassword}</div>}
                  </form>
                </div>
              </div>
            </div>
          </div>
          <div className="row">
            <div className="col-xl-9 mx-auto">
              <div className="cta-inner bg-faded text-center rounded">
                <div>
                  <header>
                    <h2 className="text-lg font-medium text-gray-900 dark:text-gray-100 fw-bold">
                      Usuń konto
                    </h2>
                    <p className="mt-1 text-sm text-gray-600 dark:text-gray-400">
                      Po usunięciu konta wszystkie jego zasoby i dane zostaną trwale usunięte.
                    </p>
                  </header>
                  <button className="btn btn-danger" onClick={openModal}>
                    Usuń konto
                  </button>
                  <Modal
                    isOpen={modalIsOpen}
                    onRequestClose={closeModal}
                    contentLabel="Wystaw opinie"
                    className="Modal"
                    overlayClassName="Overlay"
                  >
                    <form className="p-6" onSubmit={removeAccount}>
                      <div className="modal-body text-center">
                        <h2 className="text-lg font-medium">
                          Jesteś pewny, że chcesz usunąć konto?
                        </h2>

                        <p className="mt-1 text-sm">
                          Wprowadź hasło, aby potwierdzić, że chcesz trwale usunąć swoje konto.
                        </p>

                        <div className="mt-6">
                          <input
                            id="password"
                            name="password"
                            type="password"
                            className="mt-1 block w-full form-control"
                            placeholder="Hasło"
                          />
                        </div>
                        <div className="modal-footer">
                          <button
                            type="button"
                            className="btn btn-secondary"
                            data-dismiss="modal"
                            onClick={closeModal}
                          >
                            Anuluj
                          </button>
                          <button type="submit" className="btn btn-danger">
                            Usuń konto
                          </button>
                        </div>
                        {errorModal && <div
                          className="mt-2 p-lg-0 text-sm text-danger space-y-1">{errorModal}</div>}
                      </div>
                    </form>
                  </Modal>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>
    </div>
  )
}

export default ProfileEdit