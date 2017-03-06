// This is a room made by roommaker.

inherit ROOM;

int do_smell(string arg);

void create()
{
	set("short", "���ض�Ѩ");
	set("long", @LONG
���ں�����ģ�����ʲô����������ֻ����һ��������
����������˸��ƾ�����ľ��飬��һ����һ˫Ұ�޵���
��������ط���ò�Ҫ������
LONG
);
	set("objects", ([
		__DIR__"npc/lion":1,
	]) ) ;

	set("no_magic", 1);
	setup();
}

void init()
{
	add_action ("do_smell", "smell");
}

int do_smell (string arg)
{
	object* list;
	int i;

	if (arg != "grass")
		return notify_fail ("��Ҫ��ʲô��\n");

	list = all_inventory(this_player());  
	i = sizeof(list);
	while (i--) {
		if (((string)list[i]->query("id")) == "grass")
			message_vision("һ��ַ���Ȼ����$N�·����Ƽ���㡣\n", this_player());
			this_player()->move ("/u/cloud/biaoju");
			return 1;
		}

	return notify_fail ("������û�����ǲݰ���\n");
}
