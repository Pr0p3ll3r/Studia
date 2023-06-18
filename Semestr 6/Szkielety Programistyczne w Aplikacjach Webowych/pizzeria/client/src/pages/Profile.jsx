import React from 'react'
import { Link } from 'react-router-dom'

const Profile = () => {
  const handleLogout = () => {
    localStorage.clear()
    window.location.reload()
  }
  return (
    <div>
      <div className="page-section cta">
        <div className="container">
          <div className="row">
            <div className="col-xl-9 mx-auto">
              <div className="cta-inner bg-faded text-center rounded">
                <span className="section-heading-lower fw-bold">Jesteś zalogowany!</span>
                <div className="flex items-center justify-center mt-4">
                  <Link
                    to="/profile/edit"
                  >
                    Profil
                  </Link>

                  <Link
                    to="/orders"
                    className="m-2"
                  >
                    Twoje zamówienia
                  </Link>

                  <button className="px-4 py-2 btn btn-primary" onClick={handleLogout}>
                    Wyloguj się
                  </button>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  )
}

export default Profile
