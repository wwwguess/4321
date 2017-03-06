//hurt_drug.c

inherit ITEM;

void create()
{
        set_name("��ҩ",({"medicine"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�Ž�ҩ, ������������(apply)���� ��\n");
            set("unit","��");
            set("value", 2000);
        }
}

void init()
{
        add_action("apply_medicine","apply");
}

int apply_medicine()
{
        int value = 20;
        int diff;

        if(this_player()->is_fighting())
            return notify_fail("ս���в�����ҩ����!\n");
        diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
        if(!(diff))    return notify_fail("��û�����˰�?\n");
        if(value > diff) value = diff;

        message_vision("$N���Ͻ�ҩ .\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}


