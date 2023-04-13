package pl.pollub.android.app2;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class PhoneAdapter extends RecyclerView.Adapter<PhoneViewHolder> {
    private LayoutInflater inflater;
    private List<Phone> phoneList;

    public PhoneAdapter(LayoutInflater inflater) {
        this.inflater = inflater;
        this.phoneList = null;
    }

    @NonNull
    @Override
    public PhoneViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = parent.getRootView();
        return new PhoneViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull PhoneViewHolder holder, int position) {
        Phone phone = this.phoneList.get(position);
        holder.getManufacturer().setText(phone.getManufacturer());
        holder.getModel().setText(phone.getModel());
    }

    @Override
    public int getItemCount() {
        return this.phoneList != null ? this.phoneList.size() : 0;
    }

    public List<Phone> getPhoneList() {
        return phoneList;
    }

    public void setPhoneList(List<Phone> phoneList) {
        this.phoneList = phoneList;
        notifyDataSetChanged();
    }
}
