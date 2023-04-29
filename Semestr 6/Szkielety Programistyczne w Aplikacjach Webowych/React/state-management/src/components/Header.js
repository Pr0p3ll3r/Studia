function Header(props) {
    return (
        <div className="header">
        <h1>Nagłówek</h1>
        <p>Aktualny rozmiar czcionki: <strong>{props.fontSize}</strong></p>
        <p>Aktualny kolor czcionki: <strong>{props.color}</strong></p>
        <p>
          Liczba lajków: <strong>{props.counter}</strong>
        </p>
      </div>
    )
}
export default Header;