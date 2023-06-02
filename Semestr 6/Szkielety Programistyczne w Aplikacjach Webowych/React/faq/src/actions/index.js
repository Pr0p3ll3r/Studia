export const addFaqElement = (question, answer) => ({
    type: "ADD_FAQ_ELEMENT",
    question,
    answer
})

export const editFaqElement = (index, question, answer) => ({
    type: "EDIT_FAQ_ELEMENT",
    index,
    question,
    answer
})

export const deleteFaqElement = index => ({
    type: "DELETE_FAQ_ELEMENT",
    index
})