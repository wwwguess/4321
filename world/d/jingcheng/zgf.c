#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�ܹܸ���"NOR);
	set("long", @LONG
�����ǵ����ܹ���ɽ�ĸ��ڡ�������������ͷ�ߴ��ʯʨ�ӡ�
Ժ���������˻��ݡ�������һ�û����������дУ��ڸ��˴��
��Ժ�ӡ�һ�������ߵ�ͨ����Ժ��
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"xchjie4", 
 
	]));
     set("objects",([
      __DIR__"npc/yingks.c" :1,
      __DIR__"npc/xunbu.c" : 3,
    ]));
	setup();
	
}

