inherit COMBINED_ITEM;

void create()
{
        set_name("�ɵ�", ({"tablet"}));
        set("long",     "����һ���ɵ�����ʳ��λ���ɰࡣ\n"
);
        set("unit", "��");
        set("value",100); 
        set("base_unit", "��");
        set("base_weight", 10000);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
                add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        if( !arg || arg != "tablet")  return notify_fail("��Ҫ����ô��? \n");
        message_vision(
           "$N�ó�һ���ɵ����������. �Ե�̫��, ����������������..\n"
           ,this_player()  );
        this_player()->receive_heal("gin", 5);
        this_player()->receive_heal("kee", 30);
        this_player()->receive_heal("sen", 5);

        add_amount(-1);
        return 1;
} 
