inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("���",({"red"}));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long","�������������ȥ�����ˣ���޲���һ�ھ�����ȥ��\n");
 	  set("unit","��");
          set("value",100);
          set("food_remaining",1);
          set("food_supply", 80);
     }
}


