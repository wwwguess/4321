// Room: /d/temple/road1.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
һ��������ʯ���С��, ����ߴ������, ż�����뻺��Ʈ�䡣
�����ϲ�������̦, ��������Щ���ӵ�ʯ���ϡ��ϱ�ͨ������, ����
���Ǻ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/temple/corridor3",
  "northwest" : "/d/temple/road2",
]));

	setup();
}

int valid_leave(object me, string dir)
{
     if (!wizardp(this_player()) && (dir=="south" || dir=="northwest"))
     {
   	  if (this_player()->query_skill("dodge") < 50){
           if( random((int)this_player()->query("kar")) < 3 )
              {
               message_vision("$Nһ�Ų�����̦��, ��С�Ļ���һ��, �Ľų����ˤ�ڵ���������\n\n\n", this_player());
               this_player()->unconcious();
               return 0;
              }
           else return ::valid_leave(me, dir);
	   }
          else return ::valid_leave(me, dir);
        }
     else return ::valid_leave(me ,dir);
} 
         
