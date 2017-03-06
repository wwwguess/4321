// Room: /d/new_taohua/lshfroom.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
int do_open(string);
int do_close(string);
void create()
{
        set("short", "½�˷��");
        set("long", @LONG
       ���ڳ�����ӣ����ر���������϶��Ű�Ƭ��Ƭ������������״��
ȴ�ֲ���Ѱ���İ�����ô�������룬�������䣬��б���ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
//  "south" : __DIR__"yonglu6",
]));
       

        setup();
}
void init()
{
        add_action("do_open","open");
	add_action("do_close","close");
	add_action("do_read","read");
}
int do_close(string arg)
{
         object ob;
         switch (arg)
         {
         case "door":
         case "��":
             if(!query("exits/south")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N���Ź���,ȴ�����ź���һ�������ԡ�\n",this_player());
             delete("exits/south");
             return 1;
         default: return notify_fail("��Ҫ��ʲô��\n"); 
         }
         

}
int do_open(string arg)
{
         object ob;
         switch (arg)
         {
         case "door":
         case "��":
             if(query("exits/south")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N���Ŵ�\n",this_player());
             set("exits/south",__DIR__"yonglu6");
             return 1;

         default: return notify_fail("��Ҫ��ʲô��\n"); 
         }
         

}
int do_read(string arg)
{
        int lvl,exp;
        object me,where;
        me=this_player();
        where = environment(me);            

        if ( !arg && arg!="bagua" && arg!="����" && !query("exits/south"))
                return notify_fail("ʲô��\n");
	 
        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
        if (me->query("gin")<100) return notify_fail("��ľ��������ˡ�\n");
        me->add("gin", (-1)*random(100));

        message_vision("$N��ר���ж����ԡ�\n", me);
        exp=me->query("combat_exp")*10;
	lvl=100;
        switch( random(2) )
        {
            case 0:
                if ( (lvl=(int)me->query_skill("luoying-zhang", 1)) < 101)
                {          
                        if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("luoying-zhang", me->query("int")*10);
                        write("���ж����ԣ��ƺ�����Ӣ�����е��ĵá�\n");
                        me->unconcious(); 
                        me->set("no_get", 1);
                        me->set("no_get_from", 1); 
                        where->set("no_fight", 1);

                }
        break;
            case 1:
                if ( (lvl=(int)me->query_skill("lanhua-shou", 1)) < 101)
                {       if(lvl*lvl*lvl>exp) return 1;
                        me->improve_skill("lanhua-shou", me->query("int")*10);
                        write("���ж����ԣ��ƺ���������Ѩ���е��ĵá�\n");
                        me->unconcious();
                        me->set("no_get", 1);
                        me->set("no_get_from", 1); 
                        where->set("no_fight", 1);
                }
        break;
        }

        return 1;
} 
