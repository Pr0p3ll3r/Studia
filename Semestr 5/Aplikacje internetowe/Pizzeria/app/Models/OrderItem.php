<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class OrderItem extends Model
{
    use HasFactory;
    
    protected $fillable = [
        'order_id',
        'pizza_id',
        'size',
        'quantity',
        'price',
    ];
    
    public function order()
    {
        return $this->belongsTo('App\Models\Order');
    }
    
    public function pizza()
    {
        return $this->belongsTo('App\Models\Pizza');
    }
}
