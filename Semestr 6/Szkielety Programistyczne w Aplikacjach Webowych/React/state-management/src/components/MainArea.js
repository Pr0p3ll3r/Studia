function MainArea(props) {
    return (  
        <div className="main-area" style = {{fontSize: `${props.fontSize}px`, color: props.color}}>
            <p>Szkielety programistyczne w aplikacjach internetowych: Node, MongoDB, Express, React.</p>
        </div>
    )
}
export default MainArea;