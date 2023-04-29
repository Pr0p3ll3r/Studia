function Sidebar(props) {
    return (
        <div className="sidebar">
        <input type="text" value={props.fontSizeButton} onChange={props.handleFontSizeChange}/>
        <input type="text" value={props.fontColorButton}  onChange={props.handleColorChange}/>
        <button onClick={props.handleButtonClick}>
            Ustaw parametry tekstu: {props.fontSizeButton}px, {props.fontColorButton}
            </button>
        </div>
    )
}
export default Sidebar;