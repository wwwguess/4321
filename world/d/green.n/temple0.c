// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��СС��������, �����൱�İ�, һ��ʪ�����Ϸ���ڤ
ֽ��ζ��ʹ�����ڵĵ���ζ�Եú�����. ���������ǵطŸ�һЩˮ
��, һ��ľ�̵����ع���¶�������ǰ��. �����С�յر���һ��
��ª�Ľ�ֽͤ.
 
LONG
	);
    set("exits", ([
    "east" : __DIR__"path2",
]));

	setup();
	replace_program(ROOM);
}
