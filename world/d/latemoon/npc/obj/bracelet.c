#include <ansi.h>

#include <armor.h>
inherit WRISTS;

void create()
{
    set_name(HIC "�������" NOR, ({"bracelet onyx","bracelet"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "һ����������ɵ���������\n"
            "����ϸ�濴���ƺ����������� (info bracelet)��\n");
            set("unit", "��");
            set("value", 5000);
            set("no_drop", 1);
            set("armor_prop/armor",2);
            set("armor_prop/dodge", 2);
            set("armor_prop/spells", 2);
            set("wear_msg", "$N��$n�������ϡ�\n");
     }
     setup();
}

void init()
{
        if( this_player()==environment() )
            add_action("do_info","info");
            add_action("do_pray","pray");
}

int do_info(string arg)
{
        if( !arg ) return notify_fail("����֪��ʲô? \n");
        write("ʹ�� (pray start) �����ᴫ�������㡣\n");
         return 1;
}

int do_pray(string arg)
{
      string name;
       name = (string)this_player()->query("name");

         if( !arg || arg!="start" ) return notify_fail("��Ҫ����ʲô? \n");
         {
         message_vision("$N˫�ֺ��ƣ��ϵ�����\n"
             "���ϵ������������졣 ͻȻһ������.... \n",this_player() );
         this_player()->receive_damage("sen",50);
         tell_room(environment(this_player()),
               name+"����Ӱ��ʧ�ڿ����С�\n",this_player() );
         tell_room("/d/snow/inn",
              name+"����Ӱ������һ������֮�С�\n",this_player() );
         this_player()->move("/d/snow/temple");
          }
          return 1;
}
