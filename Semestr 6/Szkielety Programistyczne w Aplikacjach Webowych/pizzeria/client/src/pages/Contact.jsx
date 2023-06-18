const Contact = () => {
  return (
    <div>
      <section className="page-section cta">
        <div className="container">
          <div className="row">
            <div className="col-xl-9 mx-auto">
              <div className="cta-inner bg-faded text-center rounded">
                <h2 className="section-heading mb-5">
                  <span className="section-heading-lower fw-bold">Godziny otwarcia</span>
                </h2>
                <ul className="list-unstyled list-hours mb-5 text-left mx-auto">
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Poniedziałek
                    <span className="ms-auto">10 - 22</span>
                  </li>
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Wtorek
                    <span className="ms-auto">10 - 22</span>
                  </li>
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Środa
                    <span className="ms-auto">10 - 22</span>
                  </li>
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Czwartek
                    <span className="ms-auto">10 - 22</span>
                  </li>
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Piątek
                    <span className="ms-auto">10 - 23</span>
                  </li>
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Sobota
                    <span className="ms-auto">12 - 23</span>
                  </li>
                  <li className="list-unstyled-item list-hours-item d-flex">
                    Niedziela
                    <span className="ms-auto">12 - 22</span>
                  </li>
                </ul>
                <p className="address mb-5">
                  <em>
                    <strong>ul. Nadbystrzycka 38 D</strong>
                    <br />
                    20 – 618 Lublin
                  </em>
                </p>
                <p className="address mb-5">
                  <em>
                    <strong>Email:</strong>
                    <br />
                    <strong><a href="mailto:info@poppizza.pl">info@poppizza.pl</a></strong>
                  </em>
                </p>
                <p className="address mb-0">
                  <em>Zapraszamy do składania zamówień pod numerem telefonu:</em>
                  <br />
                  <strong className="fw-bold">12 345 67 89</strong>
                </p>
              </div>
            </div>
          </div>
        </div>
      </section>
    </div>
  )
}
export default Contact