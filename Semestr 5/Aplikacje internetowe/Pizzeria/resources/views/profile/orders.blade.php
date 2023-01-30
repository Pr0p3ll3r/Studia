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
                                <td colspan="2">Data zamówienia: {{ $order->created_at }}</td>
                                <td colspan="3">Komentarz : {{ $order->comment }}</td> 
                            </tr>
                            <tr> 
                                <td colspan="5" class="text-center">Zawartość</td>                      
                            </tr> 
                            <tr> 
                                <td colspan="1">Ilość</td> 
                                <td colspan="1">Nazwa</td>
                                <td colspan="1">Wielkość</td> 
                                <td colspan="2">Cena</td> 
                            </tr>
                            <tr> 
                                @foreach($order->items as $item)
                                <td class="col-md-1">{{ $item->quantity }}x</td> 
                                <td class="col-md-3">{{ $item->pizza->name }}</td>
                                <td class="col-md-3">{{ $item->size }}cm</td> 
                                <td class="col-md-1">{{ $item->price }}zł</td> 
                                @endforeach
                            </tr>
                            <tr> 
                                <td colspan="6" class="text-center">
                                    <h4>
                                        <span class="section-heading-lower fw-bold">Razem {{$order->totalPrice}} zł</span>
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