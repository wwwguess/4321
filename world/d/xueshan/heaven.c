//by dwolf
//97.11.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
	  ��������ǳ�˵�����ã������������ƣ�����ƮƮ�������пɼ�һλ����
����������
LONG
	);  
	set("exits", ([
		"down" : "/d/suzhou/shizx.c",
	]));                   
	set("objects", ([
		__DIR__"npc/fairy" : 1,
	]));
	setup();
}               
   
