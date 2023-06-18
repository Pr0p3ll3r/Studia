import React from 'react'
import { useState, useEffect } from 'react'
import axios from 'axios'
import Modal from 'react-modal'

const Orders = () => {
  const [orders, setOrders] = useState([])

  useEffect(() => {
    fetchOrderList()
  }, [])

  const fetchOrderList = async () => {
    try {
      const token = localStorage.getItem('token')
      const config = {
        headers: {
          Authorization: `Bearer ${token}`,
        },
      }
      const response = await axios.get('http://localhost:8080/api/order', config)
      setOrders(response.data)
    } catch (error) {
      console.error('Błąd podczas pobierania zamówień:', error)
    }
  }

  const [modalIsOpen, setIsOpen] = useState(false)

  function openModal(orderId) {
    setIsOpen(true)
    document.body.style.overflow = "hidden"
    setReviewData({ ...reviewData, orderId: orderId })
  }

  function closeModal() {
    setIsOpen(false)
    document.body.style.overflow = "auto"
    setReviewData({
      orderId: '',
      rating: '5',
      comment: '',
    })
  }

  const [reviewData, setReviewData] = useState({
    orderId: '',
    rating: '5',
    comment: '',
  })

  const handleChange = ({ currentTarget: input }) => {
    setReviewData({ ...reviewData, [input.name]: input.value })
  }

  const addReview = async (e) => {
    e.preventDefault();

    try {
      const response = await axios.post(`http://localhost:8080/api/order/review`, reviewData);
      window.location.reload()
      console.log(response.message)
    } catch (error) {
      console.error('Wystąpił błąd podczas dodawania opinii.', error);
    }
  }

  return (
    <div>
      <div className="page-section cta">
        <div className="container">
          <div className="row">
            <div className="mx-auto space-y-6">
              <div className="cta-inner bg-faded text-center rounded">
                <h2 className="section-heading mb-5">
                  <span className="section-heading-lower fw-bold text-center">Twoje zamówienia</span>
                </h2>
                {orders.length === 0 && <span className="fw-bold">Brak zamówień</span>}
                {orders.map((order) => (
                  <table className="table table-primary" key={order._id}>
                    <tbody>
                      <tr>
                        <td colSpan="2">
                          <b className='bg-transparent'>Adres: </b>
                          {order.address.street} {order.address.houseNumber} {order.address.apartmentNumber}
                        </td>
                        <td colSpan="2">
                          <b className='bg-transparent'>Data zamówienia: </b>
                          {new Date(order.createdAt).toLocaleString()}
                        </td>
                      </tr>
                      <tr>
                        <td colSpan="4">
                          <b className='bg-transparent'>Komentarz: </b>
                          {order.comment}
                        </td>
                      </tr>
                      <tr>
                        <td className="fw-bold">Ilość</td>
                        <td className="fw-bold">Nazwa</td>
                        <td className="fw-bold">Wielkość</td>
                        <td className="fw-bold">Cena</td>
                      </tr>
                      {order.items.map((item) => (
                        <tr key={item._id}>
                          <td>{item.quantity}x</td>
                          <td>{item.pizzaId.name}</td>
                          <td>{item.size}cm</td>
                          <td>{item.price}zł</td>
                        </tr>
                      ))}
                      <tr>
                        <td colSpan="4">
                          <h4 className='bg-transparent'>
                            <span className="section-heading-lower fw-bold">Razem {order.totalPrice} zł</span>
                          </h4>
                        </td></tr>
                      <tr>
                        <td colSpan="4">
                          {order.review ? (
                            <>
                              <b>Opinia: </b>
                              {order.review.comment} ({order.review.rating}/5⭐)
                            </>
                          ) : (
                            <>
                              <button className="btn btn-primary" onClick={() => openModal(order._id)}>
                                Wystaw opinie
                              </button>
                              <Modal
                                isOpen={modalIsOpen}
                                onRequestClose={closeModal}
                                contentLabel="Wystaw opinie"
                                className="Modal"
                                overlayClassName="Overlay"
                              >
                                <form className="p-6" onSubmit={addReview} method="post">
                                  <div className="modal-body text-center">
                                    <p>Podziel się swoją opinią o tym zamówieniu.</p>
                                    Ocena: {' '}
                                    <select name="rating" value={reviewData.rating} onChange={handleChange}>
                                      <option value={5}>5</option>
                                      <option value={4}>4</option>
                                      <option value={3}>3</option>
                                      <option value={2}>2</option>
                                      <option value={1}>1</option>
                                    </select>
                                    <textarea
                                      className="form-control"
                                      name="comment"
                                      id="comment"
                                      placeholder="Opinia"
                                      maxLength="500"
                                      onChange={handleChange}
                                    ></textarea>
                                  </div>
                                  <div className="modal-footer">
                                    <button
                                      type="button"
                                      className="btn btn-secondary"
                                      data-dismiss="modal"
                                      onClick={closeModal}
                                    >
                                      Anuluj
                                    </button>
                                    <button type="submit" className="btn btn-primary">
                                      Wystaw opinie
                                    </button>
                                  </div>
                                </form>
                              </Modal>
                            </>
                          )}
                        </td>
                      </tr>
                    </tbody>
                  </table>
                ))}
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  )
}

export default Orders
