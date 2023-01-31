<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class OrderFeedback extends Model
{
    use HasFactory;
    const UPDATED_AT = null;
    
    protected $fillable = [
        'order_id',
        'content'
    ];
     
    public function order()
    {
        return $this->belongsTo('App\Models\Order');
    }
}
