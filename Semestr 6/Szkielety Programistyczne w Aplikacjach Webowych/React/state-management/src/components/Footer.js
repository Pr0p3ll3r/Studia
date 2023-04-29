function Footer(props) {
    return (
        <footer className="footer">
        <p>
          Stopka <button onClick={props.handleButtonClickFooter}>Ustaw parametry tekstu na 30px, a kolor pozostaw bez zmian.</button>
        </p>
        <p>
          <button onClick={props.handleIncrement}>
            Polub tę stronę!
          </button>
        </p>
      </footer>
    )
}
export default Footer;