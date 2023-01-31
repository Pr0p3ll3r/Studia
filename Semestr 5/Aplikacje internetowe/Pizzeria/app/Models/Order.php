<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Order extends Model
{
    use HasFactory;
    
    protected $fillable = [
        'user_id',
        'totalPrice',
        'payment',
        'comment'
    ];
    
    public function items()
    {
        return $this->hasMany('App\Models\OrderItem');
    }
      
    public function user()
    {
        return $this->belongsTo('App\Models\User');
    }
    
    public function address()
    {
        return $this->hasOne('App\Models\OrderAddress');
    }
    
    public function feedback()
    {
        return $this->hasOne('App\Models\OrderFeedback');
    }
}
