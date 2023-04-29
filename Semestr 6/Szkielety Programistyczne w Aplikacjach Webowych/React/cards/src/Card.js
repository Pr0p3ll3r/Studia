export function Card(props) {
    return <div className="Card">
        <h2>{props.fullname}</h2>
        <img src={props.imageSource} alt={props.fullname} />
        <p>{props.date}</p>
        <p>{props.professions}</p>
        <p>{props.country}</p>
    </div>
}