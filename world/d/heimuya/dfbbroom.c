inherit ROOM;

void create()
{
   set("short", "����");
        set("long", @LONG
ֻ������ǽ�ڣ�������͸���ٽ��黭������ǽ�ϡ�����ɴ�֣����
��⣬������̤��ש�����Ǳ����仨����һ���飬��һ�����������ǵ�
�յ���̴��ڡ�һ���󴲰����������룬һ��Ů�������廨��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"hy",

]));
    set("objects", ([
"/class/heimuya/dfbb" : 1,
  ]) );

        setup();
        replace_program(ROOM);
}

