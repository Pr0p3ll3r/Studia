<x-app-layout>
    <section class="page-section cta">
        <div class="container">        
            <div class="row">
                <div class="mx-auto space-y-6">
                    <div class="cta-inner bg-faded text-center rounded">
                        <h2 class="section-heading mb-5">
                            <span class="section-heading-lower fw-bold text-center">Twoje zamówienia</span>
                        </h2>
                        @if($orders->isEmpty())
                        <span class="fw-bold">Brak zamówień</span>
                        @endif
                        @foreach($orders as $order)
                        <table class="table table-primary">
                            <tr>
                                <td colspan="2">Adres: {{ $order->address->street }} {{ $order->address->houseNumber }} {{ $order->address->apartmentNumber }}</td>   
                                <td colspan="2">Data zamówienia: {{ $order->created_at }}</td>                            
                            </tr>
                            <tr>
                                <td colspan="4">Komentarz: {{ $order->comment }}</td> 
                            </tr>
                            <tr>
                                <td colspan="4">Zawartość</td>                      
                            </tr> 
                            <tr>
                                <td>Ilość</td> 
                                <td>Nazwa</td>
                                <td>Wielkość</td> 
                                <td>Cena</td> 
                            </tr>
                             @foreach($order->items as $item)
                            <tr>
                                <td>{{ $item->quantity }}x</td> 
                                <td>{{ $item->pizza->name }}</td>
                                <td>{{ $item->size }}cm</td> 
                                <td>{{ $item->price }}zł</td>                
                            </tr>
                            @endforeach
                            <tr>
                                <td colspan="4">
                                    <h4>
                                        <span class="section-heading-lower fw-bold">Razem {{ $order->totalPrice }} zł</span>
                                    </h4>
                                </td>
                            </tr>
                        </table>
                        @endforeach 
                    </div>
                </div>
            </div>
        </div>	 
    </section>
</x-app-layout>