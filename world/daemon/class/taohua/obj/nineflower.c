// medicine: nineflower.c
// Jay 3/18/96

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("�Ż���¶��", ({"jiuhua wan", "nineflower", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ż���¶�衣\n");
     set("no_get",1);
                set("value", 500);
        }
        setup();
}

int do_eat(string arg)
{       
        
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n"); 
        
         if ((string)this_player()->query("family/family_name")!="�һ���")
         {    this_player()->add("max_force", 10);
             this_player()->add("max_jingli",3);
         write("�����һ���Ż���¶��,ֻ����һ������!\n");         
          }
          else
         {write("�����һ���Ż���¶�裬��ʱ�����ȫ������˻��� !\n");
             this_player()->add("max_force", 50);
             this_player()->add("max_jingli",6);
          }
       destruct(this_object());
       return 1;
}

