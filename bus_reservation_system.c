#include <stdio.h>
#include <string.h>
int main()
{
    char reg_username[30], reg_password[30], reg_mobile[15], reg_email[30], log_username[30], log_password[30], new_password[30];
    int option, choice, selection = 0, profile_choice, input_bus, requested_seat, requested_cancelseat, final_payment = 0, finalpayment_aftercancel = 0;
    int bus_number[5] = {100, 101, 102, 103, 104};
    int total_seat[5] = {50, 50, 30, 40, 45};
    int seat_booked[5] = {0, 0, 0, 0, 0};
    int cancel_seat[5] = {0, 0, 0, 0, 0};
    int remaining_seat[5] = {50, 50, 30, 40, 45};
    char source[5][30] = {"Thawe", "Chhapra", "Chhapra", "Siwan", "Tamkuhi Road"};
    char destination[5][30] = {"Siwan", "Hajipur", "Banaras", "Mau", "Gorakhpur"};
    int fare[5] = {500, 500, 300, 400, 450};
    char busname[5][30] = {"Marcopolo", "Rozy", "Anandabihar", "Aditya Travels", "Rajdhani Travels"};
    char bustype[5][30] = {"AC", "Luxurius", "Non-AC", "Sleeper", "General"};

    while (1)
    {
        printf("\n=====WELCOME======\n");

        printf("\nClick 1 for Registration and Login");
        printf("\nClick 2 for Exit Program");
        printf("\nEnter your option = ");
        scanf("%d", &option);
        int login_success =0;
        switch (option)
        {
        case 1:
            printf("\n===Registration Started===");
            printf("\nEnter user name = ");
            scanf(" %29[^\n]", reg_username);
            printf("Please Enter Password = ");
            scanf(" %29[^\n]", reg_password);
            printf("Enter mobile number = ");
            scanf(" %14[^\n]", reg_mobile);
            printf("Enter Email Id = ");
            scanf(" %29s", reg_email);
            printf("\n\nSuccessfully Registered! Account created Welcome %s", reg_username);
            printf("\n===Login profile===");
            while (1)
            {
                printf("\nEnter username = ");
                scanf(" %29[^\n]", log_username);
                printf("\nEnter password = ");
                scanf(" %29[^\n]", log_password);
                if (strcmp(reg_username, log_username) == 0 && strcmp(reg_password, log_password) == 0)
                {
                    printf("\n=====Successfully login=====");
                    login_success=1;
                    break;
                }
                else
                {
                    printf("\nPlease enter correct login info....");
                }
            }
            break;

        case 2:
            printf("\n====EXIT PROGRAM=====");
            return 0;
        default:
            printf("Please enter valid option");
            break;
        }
        if(login_success==1)
        {
            while (1)
        {
            printf("\n\n=====BUS RESERVATION SYSTEM=====");
            printf("\nEnter 1 for 'Book a Ticket'");
            printf("\nEnter 2 for 'Cancel a Ticket'");
            printf("\nEnter 3 for see 'Check Bus Status'");
            printf("\nEnter 4 for'View Bus Details and Schedule'");
            printf("\nEnter 5 for your 'Payment Method'");
            printf("\nEnter 6 for Receipt");
            printf("\nEnter 7 for 'Profile Management'");
            printf("\nEnter 8 for 'Logout'");
            printf("\nSelect your choice = ");
            scanf("%d", &choice);

            int found = 0;
            switch (choice)
            {
            case 1:
                printf("\n=====Book a Ticket=====");
                printf("\nPlease enter bus number = ");
                scanf("%d", &input_bus);
                found = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (input_bus == bus_number[i])
                    {
                        found = 1;
                        printf("Enter number of seat to booked = ");
                        scanf("%d", &requested_seat);

                        if (requested_seat <= remaining_seat[i])
                        {
                            seat_booked[i] += requested_seat;
                            remaining_seat[i] -= requested_seat;
                            final_payment = requested_seat * fare[i];
                            printf("\nYour payment would be %d", final_payment);
                            printf("\nSuccessfully Booking !! %d seat has been booked on bus number %d", requested_seat, input_bus);
                        }
                        else
                        {
                            printf("\nSorry! Only %d seats are available.", remaining_seat[i]);
                        }
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("\nBus number is invalid");
                }
                break;
            case 2:
                printf("\n====Cancel a ticket====");
                printf("\nPlease enter Bus Number = ");
                scanf("%d", &input_bus);
                found = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (input_bus == bus_number[i])
                    {
                        found = 1;
                        printf("Please enter number of seats to cancel = ");
                        scanf("%d", &requested_cancelseat);

                        if (requested_cancelseat <= seat_booked[i])
                        {
                            seat_booked[i] -= requested_cancelseat;
                            cancel_seat[i] += requested_cancelseat;
                            remaining_seat[i] += requested_cancelseat;
                            finalpayment_aftercancel = (seat_booked[i] * fare[i]);
                            printf("Final payment would be %d", finalpayment_aftercancel);
                            printf("\nSuccessfully Cancelled !! %d seat has been cancelled on bus number %d", requested_cancelseat, input_bus);
                        }
                        else
                        {
                            printf("\nYou haven't booked that many seats!");
                        }
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("\nBus number is invalid");
                }
                break;
            case 3:
                printf("\n====Bus Details====");
                printf("\nPlease enter Bus Number = ");
                scanf("%d", &input_bus);
                found = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (input_bus == bus_number[i])
                    {
                        found = 1;
                        printf("\nBus Number              :      %d", bus_number[i]);
                        printf("\nBus Name                :       %s", busname[i]);
                        printf("\nSource City             :      %s", source[i]);
                        printf("\nDestination City      :       %s", destination[i]);
                        printf("\nTotal Seats             :       %d", total_seat[i]);
                        printf("\nAvailable Seat        :       %d", remaining_seat[i]);
                        printf("\nFare                    :       %d", fare[i]);
                        printf("\nFinal payment would be = %d", seat_booked[i] * fare[i]);
                        printf("\nSeat Booked              :          %d", seat_booked[i]);
                        printf("\nBus Type                  :       %s", bustype[i]);
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("\nBus not found");
                }
                break;
            case 4:
                for (int i = 0; i < 5; i++)
                {
                    printf("\nBus number      :       %d", bus_number[i]);
                    printf("\nSource          :       %s", source[i]);
                    printf("\nDestination     :       %s", destination[i]);
                    printf("\nFare            :       %d", fare[i]);
                    printf("\nTotal seat      :       %d", total_seat[i]);
                    printf("\nSeat booked     :       %d", seat_booked[i]);
                    printf("\nCanceled seat   :       %d", cancel_seat[i]);
                    printf("\nRemaining seat   :       %d", remaining_seat[i]);

                    printf("\n\n");
                }
                printf("\n===Routes & Timing===\n");

                printf("\n==Thawe to Siwan Route==");
                printf("\nThawe to Hathwa       :       4:20 AM to 4:35 AM");
                printf("\nHathwa to Amlori Sarsar  :    4:40 AM to 4:58 AM");
                printf("\nAmlori Sarsar to Siwan   :    5:02 AM To 5:26 AM");
                printf("\n");

                printf("\n==Chhapra to Hajipur Route==");
                printf("\nChhapra to Dighwara         :       1:40 AM to 2:40 AM");
                printf("\nDighwara to Sonpur          :       2:45 AM to 3:10 AM");
                printf("\nSonpur To Hajipur         :       3:13 AM to 3:21 AM");
                printf("\n");

                printf("\n==Chhapra to Banaras Route==");
                printf("\nChhapra to Balia          :       10:50 PM to 12:10 AM");
                printf("\nBalia to Ghazipur city    :       12:13 AM to 1:10 AM");
                printf("\nGhazipur to Varansi       :       1:14 AM to 3:15 AM");
                printf("\n");

                printf("\n==Siwan to Mau Route==");
                printf("\nSiwan to Jiradei        :       9:45 AM to 11:25 AM");
                printf("\nBhatni to Mau           :       11:40 Am to 1:10 PM");
                printf("\n");

                printf("\n==Tamkuhi Road to Gorakhpur Route==");
                printf("\nTamkuhi Road to Padrauna          :       12:30 AM to 1:15 AM");
                printf("\nPadrauna to Kaptanganj            :       1:20 AM to 2:10 AM");
                printf("\nKaptanganj to Gorakhpur           :       3:20 AM to 3:35 AM");
                printf("\n");
                break;
            case 5:
                printf("\n====Payment Method====");
                printf("\nEnter 1 for 'Payment with Cash'");
                printf("\nEnter 2 for 'Payment with Card'");
                printf("\nEnter 3 for 'Payment with Google Pay'");
                printf("\nEnter 4 for 'Payment with Phone Pay'");
                printf("\nEnter your selection = ");
                scanf("%d", &selection);
                switch (selection)
                {
                case 1:
                    printf("Payment with Cash");
                    break;
                case 2:
                    printf("Payment with Card");
                    break;
                case 3:
                    printf("Payment with Google Pay");
                    break;
                case 4:
                    printf("Payment with Phone Pay");
                    break;
                default:
                    printf("Invalid selection");
                    break;
                }
                break;
            case 6:

                printf("Enter bus number = ");
                scanf("%d", &input_bus);
                found = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (input_bus == bus_number[i])
                    {
                        found = 1;
                        printf("\n====Billing Invoice====");
                        printf("\nUser Name               :       %s", reg_username);
                        printf("\nUser Mobile No.         :         %s", reg_mobile);
                        printf("\nUser Email Id             :       %s", reg_email);
                        printf("\nBus Number              :      %d", bus_number[i]);
                        printf("\nBus Name              :       %s", busname[i]);
                        printf("\nSource City           :      %s", source[i]);
                        printf("\nDestination City      :       %s", destination[i]);
                        printf("\nTotal Seats           :       %d", total_seat[i]);
                        printf("\nAvailable Seat        :       %d", remaining_seat[i]);
                        printf("\nFare                    :       %d", fare[i]);
                        printf("\nBus Type                  :       %s", bustype[i]);
                        printf("\nFinal payment would be = %d", seat_booked[i] * fare[i]);

                        printf("\nPayment Method          :       ");
                        if (selection == 1)
                            printf("Cash");
                        else if (selection == 2)
                            printf("Card");
                        else if (selection == 3)
                            printf("Google Pay");
                        else if (selection == 4)
                            printf("Phone Pay");
                        else
                            printf("Not Selected Yet");

                        printf("\nSeat Booked              :          %d", seat_booked[i]);
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("\nBus number is invalid");
                }
                break;
            case 7:
                printf("\nProfile Management");
                printf("\nEnter 1 for 'View Profile'");
                printf("\nEnter 2 for 'Change Password'");
                printf("\nEnter your Profile Choice = ");
                scanf("%d", &profile_choice);
                switch(profile_choice)
                {
                    case 1:
                        printf("\n====User's Profile====");
                        printf("\nUsers name    :   %s",reg_username);
                        printf("\nMobile        :   %s",reg_mobile);
                        printf("\nEmail Id      :   %s",reg_email);
                        printf("\n=================================");
                        break;
                    case 2:
                        printf("====Change Password====");
                        printf("\nEnter your Current Password = ");
                        scanf(" %29[^\n]",log_password);
                        if(strcmp(reg_password,log_password)==0)
                        {
                            printf("Enter New Password = ");
                            scanf(" %29[^\n]", new_password);
                            strcpy(reg_password,new_password);
                            printf("\nPassword Changed Successfully");
                        }
                        else
                        {
                            printf("\nIncorrect Current Password! Password Changed Failed");
                        }
                        break;
                    default:
                        printf("\nInvalid Option");
                        break;
                }
                break;
            case 8:
                printf("==Logout Successful==");
                break;
            default:
                printf("Please enter valid order");
                break;
            }
            if (choice == 8)
            {
                break;
            }
        }
        }
        
    }

    return 0;
}