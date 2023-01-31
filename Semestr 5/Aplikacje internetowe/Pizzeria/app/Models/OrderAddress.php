<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class OrderAddress extends Model
{
    use HasFactory;
    public $timestamps = false;
    
    protected $fillable = [
        'order_id',
        'street',
        'houseNumber',
        'apartmentNumber'
    ];
     
    public function order()
    {
        return $this->belongsTo('App\Models\Order');
    }
}
