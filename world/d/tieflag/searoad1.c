// searoad.c
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
·���ϵ�ɳʯԽ��Խϸ��������������һ����ζ��Խ��ǰ�ߣ���ζԽ���ԡ�Զ��
�������������İ���������ż���߹�ȥһ��������ˮ�Ƶ������
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"searoad",
  		  "south" : __DIR__"seaside",
		]));         
		set("objects",([
        	__DIR__"npc/fishman" : 1,
       	]) );
        set("outdoors", "tieflag");
        setup();
}
