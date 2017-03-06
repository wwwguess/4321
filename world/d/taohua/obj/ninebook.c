
// Book: /d/new_taohua/obj/ninebook.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.


inherit ITEM;
int do_read(string);
void create()
{
        set_name("�����澭",({ "ninebook","book" }));
        set_weight(100); 
	set("no_get",1);
	set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ�������ֵ���Ƥ������д��һЩ�����书���ķ���\n");
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
        switch( random(3) )
        {
            case 0:
                if ( (lvl=(int)me->query_skill("cuixin-zhang", 1)) < 180)
                {          
                        if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("cuixin-zhang", me->query("int")/3);
                        write("���ж������澭���ƺ��Դ������е��ĵá�\n");
                        me->set_temp("stone_learned",1);
                }
        break;
            case 1:
                if ( (lvl=(int)me->query_skill("ninemoon-zhua", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("ninemoon-zhua", me->query("int")/3);
                        write("���ж������澭���ƺ��Ծ����׹�צ�е��ĵá�\n");
                        me->set_temp("stone_learned",1);
                }
        break;
            case 2:
                if ( (lvl=(int)me->query_skill("yihun-dafa", 1)) < 180)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("yihun-dafa", me->query("int")/10);
                        write("���ж������澭���ƺ����ƻ���е��ĵá�\n");
                }
        break;
        }

        return 1;
}
