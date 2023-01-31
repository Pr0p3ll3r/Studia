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
                                <td colspan="2"><b>Adres: </b>{{ $order->address->street }} {{ $order->address->houseNumber }} {{ $order->address->apartmentNumber }}</td>   
                                <td colspan="2"><b>Data zamówienia: </b>{{ $order->created_at }}</td>                            
                            </tr>
                            <tr>
                                <td colspan="4"><b>Komentarz: </b>{{ $order->comment }}</td> 
                            </tr>
                            <tr>
                                <td colspan="4" class="fw-bold">Zawartość</td>                      
                            </tr> 
                            <tr>
                                <td class="fw-bold">Ilość</td> 
                                <td class="fw-bold">Nazwa</td>
                                <td class="fw-bold">Wielkość</td> 
                                <td class="fw-bold">Cena</td> 
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
                                    @php
                                    $feedback = DB::table('order_feedback')
                                        ->join('orders', 'order_feedback.order_id', '=', 'orders.id')
                                        ->where('orders.id', $order->id)
                                        ->first();
                                    @endphp
                                    @if(isset($feedback))
                                </td>
                            <tr>
                                <td colspan="4">
                                    <b>Opinia: </b>{{ $feedback->content }}
                                </td>
                            </tr>
                            @else
                            <x-primary-button x-data="" x-on:click.prevent="$dispatch('open-modal', 'give-feedback{{ $order->id }}')">Wystaw opinie</x-primary-button>
                            @endif
                            </td>
                            </tr>
                        </table>                               
                        <x-modal name="give-feedback{{ $order->id }}" focusable>
                            <form method="post" action="{{ route('order.feedback') }}" class="p-6">
                                @csrf

                                <p class="mt-1 text-sm text-gray-600 dark:text-gray-400">
                                    Podziel się swoją opinią o tym zamówieniu.
                                </p>

                                <div class="mt-6">
                                    <x-input-label for="feedback" value="Feedback" class="sr-only" />

                                    <textarea placeholder="Opinia" class="form-control form-control-sm" name="feedback" id="feedback" maxlength="500"></textarea> 

                                    <x-input-error class="mt-2" :messages="$errors->get('feedback')" />
                                </div>    

                                <input type="hidden" value="{{ $order->id }}" name="id">

                                <div class="mt-6 flex justify-end">
                                    <x-secondary-button x-on:click="$dispatch('close')">
                                        {{ __('Cancel') }}
                                    </x-secondary-button>
                                    <x-primary-button>Wystaw opinie</x-primary-button>          
                                </div>
                            </form>
                        </x-modal>                                                 
                        @endforeach 
                    </div>
                </div>
            </div>
        </div>	       
    </section>
</x-app-layout>