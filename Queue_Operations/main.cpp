
#include "QueueArray.h"
#include "QueueLinkedList.h"

int main( void )
{
	int data = 0;
	QueueArray array;
	QueueLinkedList list;
	while( 1 )
	{
		cout<<"Please select option"<<endl;
		cout<<"1.Queue using array"<<endl;
		cout<<"2.Queue using linked list"<<endl;
		cin>>data;
		switch( data )
		{
		case 1:
		{
			cout<<"Please select option"<<endl;
			cout<<"1.For add"<<endl;
			cout<<"2.For delete"<<endl;
			cin>>data;
			switch( data )
			{
			case 1:
			{
				cout<<"Please enter data"<<endl;
				cin>>data;
				array.add_data( data );
				array.display_data();
			}
			break;
			case 2:
			{
				array.delete_data();
				array.display_data();
			}
			break;
			default:
			{

			}
			break;
			}
		}
		break;
		case 2:
		{
			cout<<"Please select option"<<endl;
			cout<<"1.For add"<<endl;
			cout<<"2.For delete"<<endl;
			cin>>data;
			switch( data )
			{
			case 1:
			{
				cout<<"Please enter data"<<endl;
				cin>>data;
				list.add_data( data );
				list.display_data();
			}
			break;
			case 2:
			{
				list.delete_data();
				list.display_data();
			}
			break;
			default:
			{

			}
			break;
			}
		}
		break;
		default:
		{

		}
		break;
		}
		//		break;
	}
	return 0;
}



