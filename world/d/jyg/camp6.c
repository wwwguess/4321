// ROOM:__DIR__"camp6"
// by solor (98.2.21)

inherit ROOM;
void create()
{
        set("short","偏将营帐");
	set("long",@LONG                                   
这里是偏将的营帐，李将军常和旗牌官一起在这儿聊天。
向东北是副将营帐，但没有经过「允许」是不得
进入的。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/pianjiang" : 1,
		__DIR__"npc/qipaiguan" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
