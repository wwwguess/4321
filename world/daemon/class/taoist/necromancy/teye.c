// earth-warp.c   write by sb 97.11.14

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int scribe(object me, object sheet, string arg)
{ object env;
        if( me->is_fighting() ) return notify_fail("������ս���У�\n");
        
        if( (int)me->query("mana") < 50 ) return 
notify_fail("��ķ��������ˣ�\n");
        if( (int)me->query("sen") < 10 ) return 
notify_fail("��ľ��񲻹����У�\n");
        destruct(sheet);
sheet=new("/obj/sbaa/seal1.c");
            sheet->move(me);
                    sheet->set_name(YEL "����ͨ��" NOR, ({ "earth-warp sheet", 
"sheet"}) );   
   
        me->add("mana", -50);
        me->receive_damage("sen", 10);

        return 1;
}
