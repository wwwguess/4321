// item: yaofang.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}


void create()
{
        set_name("�Ż���¶��ҩ��", ({"yao fang", "fang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�žŻ���¶���ҩ����ͨ��ݣ���̴��������⣬ѩ����\n");
                set("value", 10);
        }
        setup();
}

