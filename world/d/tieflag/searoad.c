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
        set("objects",([
        	__DIR__"npc/fishman" : 1,
       	]) );
        set("exits", ([ 
  "east" : __DIR__"searoad1",
  "west" : __DIR__"plain",
]));
        set("outdoors", "tieflag");
        setup();
}
int valid_leave(object who,string dir)
{
   	if(userp(who) && random(5))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}