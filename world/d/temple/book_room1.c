// Room: /d/temple/book_room1.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
���������Ĺ����ղ��鼮�ĵط�, ���ܵ�����϶����������顣
��Щ���Ѿ��ɵ�ֽ�Ŷ�������, ��һ�����ܾͻ�ɢ��������ɷɻҡ�
������ϸ�Ŀ��˿�, �������ﶼֻ��ЩѰ�����޵����鼮, �ƺ�û��
ʲô�ر�ġ���������һ��СС��ľ��ͨ����¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"book_room2",
  "out" : __DIR__"road2",
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
     if ( dir=="out" )
          {
           message_vision("\n$N�����Ŵ����˳�ȥ, ���ְ��Ŵ��ϡ�\n\n", this_player());
           tell_room(__DIR__"road2", "�㿴���ؾ�¥���Ŵ����, �������˳�����˳�ְ��Ŵ��ϡ�\n\n");
           ::valid_leave(me, dir); 
          }
     return 1;
}
