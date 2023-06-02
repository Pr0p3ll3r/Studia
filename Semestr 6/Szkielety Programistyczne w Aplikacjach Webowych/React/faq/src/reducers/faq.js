const faq = (state = [], action) => {
    let faq
    switch (action.type) {
        case "ADD_FAQ_ELEMENT":
            return [
                ...state,
                {
                    question: action.question,
                    answer: action.answer
                }
            ]
        case "EDIT_FAQ_ ELEMENT ":
            faq = [...state]
            faq[action.index] = {
                question: action.question,
                answer: action.answer
            }
            return faq
        case "DELETE_FAQ_ ELEMENT ":
            faq = [...state]
            faq.splice(action.index, 1)
            return faq
        default:
            return state
    }
}

export default faq
