// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit ROOM;

void init();
int do_lin(string);


void create()
{
        set("short", "��ĦԺ��¥");
        set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף���
�ٰ����ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼����
�ϱ�ɽǽ�Ǹ߼��ݶ��Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ���
�����ţ������а��ż��Ű���ڭ�ͼ����ţ���λ��ɮ�����붨�С�
LONG
        );

        set("exits", ([
                "down" : __DIR__"dmyuan",
        ]));

        set("objects",([
                CLASS_D("shaolin") + "/xuan-bei" : 1,
                __DIR__"npc/xiao-bei" : 1,
        ]));
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_lin", "lingwu");
}


int do_lin(string arg)
{
   object me= this_player();
        object where = environment(me);
        string skillname;
        int skill, skill_basic;
        int cost; 

        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( !arg ) return notify_fail("����ʲô��\n");

        skill_basic = me->query_skill(arg, 1);

        if( skill_basic < 1 )
         return notify_fail("�㻹ûѧ������ܰɣ������ȥ��̱��ˡ�\n");

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
             return notify_fail("��ֻ������ enable �˸߼����ܵĻ������ܡ�\n");
        skill = me->query_skill(skillname, 1);

        if( skill_basic >= skill)
         return notify_fail("��Ļ����������ĸ߼����򻹸ߣ�\n");
        cost=20;
        if( (int)me->query("sen") > cost ) {
          me->improve_skill(arg, random((int)me->query_int()*2)+1);
        
          write( HIY "���" + to_chinese(arg) + "�����ˣ�\n" NOR);
         } else {
           cost=me->query("sen");
           write("�����ڹ���ƣ��,�޷������������򹦷�\n");
         }

         me->receive_damage("sen", cost );
                return 1;
}

int valid_leave(object me, string dir)
{
        int i;
        if( present("nine book", this_player())
        && (objectp(present("xuanbei dashi", environment(me)))) )
        {
                if (dir == "down" && !(int)me->query("readed"))
                {    
                     me->set("readed",1);
                     i=(int)me->query("int");
                     i=i+5;
                     me->set("int",i);
		     i=(int)me->query("con");
	             i=i+5;
                     me->set("con",i);
                     i=(int)me->query("dex");
                     i=i+5;
                     me->set("dex",i);
                     i=(int)me->query("str");
                     i=i+5;
                     me->set("str",i);
                     write("����ͻȻ˵��:��ʩ�������Ȿ�����飬��˼��\n");
                     write("��֮����������������㣬�ǹ���ʤʵ������ʤ����...��\n"); 
                     write("���˼�������ѧ���⣬��Ȼ���ʡ�\n");
                     return ::valid_leave(me, dir);
                }
        }
        return ::valid_leave(me, dir);
}
