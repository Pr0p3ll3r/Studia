import { useState } from "react"
import { useSelector, useDispatch } from "react-redux"
import { addFaqElement } from "../actions"
import FaqElement from "./FaqElement"

function Faq() {
    const faqList = useSelector((state) => state.faq)
    const dispatch = useDispatch()
    const [question, setQuestion] = useState("")
    const [answer, setAnswer] = useState("")

    const onChangeAnswer = (e) => {
        setAnswer(e.target.value)
    }

    const onChangeQuestion = (e) => {
        setQuestion(e.target.value)
    }

    const onSubmit = (e) => {
        e.preventDefault()
        setQuestion("")
        dispatch(addFaqElement(question, answer))
        setAnswer("")
    };

    return (
        <div>
            <ul>
                {faqList.map((elem, index) => (
                    <FaqElement
                        key={index}
                        question={elem.question}
                        answer={elem.answer}
                        index={index}
                    />
                ))}
            </ul>
            <form onSubmit={onSubmit}>
                <label>
                    Question:{" "}
                    <input
                        name="question"
                        type="text"
                        value={question}
                        onChange={onChangeQuestion}
                    />
                </label>
                <label>
                    Answer:{" "}
                    <textarea name="answer" value={answer} onChange={onChangeAnswer} />
                </label>
                <input type="submit" value="Add" />
            </form>
        </div>
    );
}
export default Faq