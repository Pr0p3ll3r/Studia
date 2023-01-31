<?php

namespace App\Http\Controllers;

use Auth;
use Illuminate\Http\Request;
use Illuminate\Http\RedirectResponse;
use App\Http\Controllers\CartController;
use App\Models\Order;
use App\Models\OrderItem;
use App\Models\OrderAddress;
use App\Models\OrderFeedback;

class OrderController extends Controller
{
    public function create() 
    {
        $orders = Order::all();
        return view('profile.orders', ['orders' => $orders]);
    }   
    
    public function ordered() 
    {
        if (url()->previous() != url('cart')) {
            return redirect()->to('/'); 
        }
        return view('pages.ordered');
    }   

    public function store(Request $request): RedirectResponse
    {
        $request->validate([
            'street' => ['required', 'string', 'max:255', 'alpha'],
            'houseNumber' => ['required', 'string', 'max:5', 'alpha_num'],
            'apartmentNumber' => ['string', 'max:5', 'nullable', 'alpha_num'],
            'comment' => ['string', 'max:255', 'nullable']
        ]);       
        
        $order = Order::create([
            'user_id' => Auth::id(),
            'totalPrice' => CartController::getTotalPrice(),
            'payment' => $request->payment,
            'comment' => $request->comment
        ]);
        
        OrderAddress::create([
            'order_id' => $order->id,
            'street' => $request->street,
            'houseNumber' => $request->houseNumber,
            'apartmentNumber' =>  $request->apartmentNumber,
        ]);
        
        $cart = session('cart');    
        foreach($cart as $id => $item)
        {
            OrderItem::create([
                'order_id' => $order->id,
                'pizza_id' => $id - $item['size'],
                'size' => $item['size'],
                'quantity' => $item['quantity'],
                'price' => $item['price']
            ]);
        }

        session()->forget('cart');      
        return redirect('/ordered'); 
    }
    
    public function feedback(Request $request): RedirectResponse
    {
        $request->validate([
            'feedback' => ['required', 'string', 'max:500']
        ]);
        
        OrderFeedback::create([
            'order_id' => $request->id,
            'content' => $request->feedback
        ]);
        
        return redirect('/orders'); 
    }
}
