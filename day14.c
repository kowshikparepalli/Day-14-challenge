#include <stdio.h>
int main ()
{
    int customers, room_type, num_days, total_rooms = 0, i;
    float rate, base_fare, add_services = 0, sub_total, discount = 0, gst, final_bill;
    float total_revenue = 0, highest_bill = 0, lowest_bill = 999999;
    char name[50],breakfast, gym_access, wifi;
    //input
    printf("enter number of customers = ");
    scanf("%d",&customers);
    for(i = 1; i <= customers; i++)
    {
        printf("\n ---customers = %d---\n",i);
        printf("enter name of customers = ");
        scanf("%s",name);
        printf("enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite) = ");
        scanf("%d",&room_type);
        if(room_type == 1)
            rate = 2500;
        else if(room_type == 2)
            rate = 4000;
        else if (room_type == 3)
            rate = 6000;
        else
        {
            printf("invalid room type ! Defaulting to Deluxe Room.\n");
            rate = 2500;
        }
        printf("enter the number of days = ");
        scanf("%d",&num_days);
            base_fare = rate * num_days;
        printf("Breakfast (Y/N) = ");
        scanf(" %c", &breakfast);
        printf("wifi (Y/N) = ");
        scanf(" %c",&wifi);
        printf("Gym access (Y/N) = ");
        scanf(" %c",&gym_access);
        if(breakfast == 'Y' || breakfast == 'y')
            add_services += 300* num_days;
        if(wifi == 'Y' || wifi == 'y')
            add_services += 100* num_days;
        if(gym_access == 'Y' || gym_access == 'y')
            add_services += 200* num_days;
            sub_total = base_fare + add_services;
            discount = sub_total / 10;
        if(sub_total > 10000)
            discount = sub_total * 0.10;
        else
            discount =0;
            sub_total = sub_total - discount;
            gst = sub_total * 0.12;
            final_bill = sub_total + gst;
        printf("Base Fare: %.2f\n", base_fare);
        printf("Additional Services: %.2f\n", add_services);
        printf("Subtotal: %.2f\n", base_fare + add_services);
        printf("Discount: %.2f\n", discount);
        printf("GST (12%%): %.2f\n", gst);
        printf("Final Bill: %.2f\n", final_bill);
            total_rooms++;
            total_revenue += final_bill;
        if (final_bill > highest_bill)
            highest_bill = final_bill;
        if (final_bill < lowest_bill)
            lowest_bill = final_bill;
    }
    //output
    printf("\n---Hotel Summary---\n");
    printf("Total Rooms Booked: %d\n", total_rooms);
    printf("Total Revenue: %.2f\n", total_revenue);
    printf("Highest Bill: %.2f\n", highest_bill);
    printf("Lowest Bill: %.2f\n", lowest_bill);
    return 0;
}