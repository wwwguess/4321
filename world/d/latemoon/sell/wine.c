inherit COMBINED_ITEM;

void create()
{
        set_name("Ů����", ({"wine"}));
        set("long",
   "����һ̳��ζŨ���ĳ����Ͼƣ��Ǵ������Ů���ȵľơ�\n"
   "�������ţ��������Ŷ!���е������ (drink)\n");
        set("unit", "̳");
        set("base_unit", "̳");
        set("base_weight", 20000);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
            add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        if( !arg ) return notify_fail("��Ҫ����ô��? \n");
        message_vision(
           "$N����һ̳�ƣ��������Ĵ�ں�����ȥ��\n"
           "ֻ��$N���Ϸ���һ����Σ����Ӳ�����������! \n",this_player()  );
        this_player()->receive_damage("gin",10);
        this_player()->receive_heal("sen",20);

        add_amount(-1);
        return 1;
}
