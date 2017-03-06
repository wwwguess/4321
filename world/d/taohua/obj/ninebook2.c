
// Book: /d/new_taohua/obj/ninebook2.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit ITEM;
int do_read(string);
void create()
{
        set_name("�����澭���Ͼ�",({ "nine book","book" }));
        set_weight(100);
        set("no_get",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ��ֽ������д��һЩ�����������ķ���\n");
                }

}
void init()
{
        add_action("do_read", "read");
}



int do_read(string arg)
{
        int lvl,exp;
        object me;
        me=this_player();

        if ( !arg && arg!="book" && arg!="ninebook" )
                return notify_fail("ʲô��1 \n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
        if (me->query("sen")<100) return notify_fail("��ľ��������ˡ�\n");
        me->add("sen", (-1)*random(100));

        message_vision("$N��ר���ж������澭��\n", me);
        exp=me->query("combat_exp")*10;
        lvl=180;
        if (me->query("readed")) 
        {
          if ( (lvl=(int)me->query_skill("yihun-dafa", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
       me->improve_skill("yihun-dafa",me->query_skill("literate",1)/25);
                        me->improve_skill("yihun-dafa", me->query("int")/3);
                        write("���ж������澭���ƺ����ƻ���е��ĵá�\n");
                }   
          return 1;
         }     

        switch( random(2) )
        {
            case 0:
                
                {
                        write("���ж������澭��ͻȻ����������һЩ���ġ�\n");
			write(RED "˹���ǣ������ɵá�\n" NOR);
			write(RED "˹��ȷ�飬�����Ĳ�Ӣ��\n" NOR);
		
                }
        break;

            case 1:
                if ( (lvl=(int)me->query_skill("yihun-dafa", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("yihun-dafa", me->query("int")/3);
                        write("���ж������澭���ƺ����ƻ���е��ĵá�\n");
                }
        break;
        }

        return 1;
}
