// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��̴��", ({"zitan hua", "hua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ֻ���ڻ�ɽ֮���ϲ�����������̴����\n");
                set("value", 10);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
             this_player()->add("food", 20);

// function of this medicine needed here

message_vision("$N����һ����̴����ֻ����һ������ !\n", this_player());

       destruct(this_object());
       return 1;
}

