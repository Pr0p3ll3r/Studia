import { Link } from "react-router-dom"

const Main = () => {
    return (
        <div>
            <section className="page-section clear-fix">
            <div className="container">
                <div className="row">
                    <div className="intro-text text-center p-5">
                        <h2 className="section-heading">
                            <span className="text-white fw-bold fs-1">Najlepsza pizza w mieście</span>
                        </h2>
                        <p className="text-white fw-bold fs-4">Zamów online lub Zadzwoń 12 345 67 89</p>
                        <div className="intro-button mx-auto"><Link to="/menu" className="btn btn-primary btn-xl fs-6 text-uppercase">Zamów online</Link></div>
                    </div>
                </div>
            </div>
            </section>
            <section className="page-section cta">
                <div className="container">
                    <div className="row">
                        <div className="col-xl-9 mx-auto">
                            <div className="cta-inner bg-faded text-center rounded">
                                <h2 className="section-heading mb-4">
                                    <span className="section-heading-lower fw-bold">Witamy!</span>
                                </h2>
                                <p className="mb-0"> Korzystając z okazji zapraszamy do naszej Pizzerii. Oferujemy ciepłą, przyjazną atmosferę do wspólnego posiłku z rodziną i przyjaciółmi o każdej porze dnia i wieczoru!</p>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
        </div>
    )
}

export default Main