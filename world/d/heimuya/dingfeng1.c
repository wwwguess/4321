// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <ansi.h>
inherit ROOM;
string *make_msg = ({
    HIG "ͭ���������������½�\n\n" NOR,
    HIG "������ס�½�\n\n" NOR,
    HIG "������ס�½�\n\n" NOR,
    HIG "������ס�½�\n\n" NOR,
    HIG "������ס�½�\n\n" NOR,
    HIG "������ס�½�\n\n" NOR,
    HIG "������ס�½�\n\n" NOR,
    HIG "�쵽����\n\n" NOR,

});
        


void create()
{
	set("short","ƽ��");
	set("long", @LONG
һС��ƽ��,������Ż��ֺͽ�������һ��������,�������º�ľ�µ�
Ҫ����ֻ�г�ʾ(chushi)����
LONG
	);

	set("exits", ([
                "north" :__DIR__"dingfeng2",
	]));


        set("objects",([
                __DIR__"npc/jiao_zhong" : 4,
        ]));
	
	set("outdoors", "heimuya");
	setup();
}

void init()
{
        add_action("do_chushi", "chushi");
}

          
int do_chushi()
{
        object who,*inv;
        int i;          
         
         who=this_player();
         inv = all_inventory(who);
         for(i=0; i<sizeof(inv); i++)
         {
         if(strsrch(inv[i]->query("name"),"����")==-1)continue;
         write(HIR "ץ���˱������!!.\n" NOR);
	 who->move(__DIR__"zhulan");
         call_out( "sanya", 3, who, 0 );

         return 1;
         }
         write(HIR "����������Ķ�ȥ��?\n��ȥ��һ��!!\n" NOR);
who->move("/d/heimuya/kezhan");
         return 1;
}

void sanya(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     	
     if( ++stage < sizeof(make_msg) ) {
	 
         call_out( "sanya", 2, who, stage );
         return;
     } else
        who->move("/d/heimuya/shanjiao19");
          tell_object(who,YEL "������!\n" NOR);
    return;
}
 

