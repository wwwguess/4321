// wu-shi1.c ������ʿ

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "wei shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����λ������ʿ�������ּף���ִ������˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
	set("combat_exp", 100000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 30);
	set("con", 25);
	set("int", 20);
	set("dex", 30);

	set("max_kee", 500);
	set("eff_kee", 500);
	set("kee", 500);
	set("max_gin", 200);
	set("gin", 200);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 30);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	setup();

        carry_object("/d/taishan/obj/gangjian")->wield();
        carry_object("/d/taishan/obj/tiejia")->wear();
}

void init()
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/d/taishan/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
	ob2 = load_object("/d/taishan/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/d/taishan/npc/fa-e");
	fae = ob3->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "������ʿ���𳤽�����$N�����󺰣��������꣬���꣬�����꣡\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == shangshan ) {
		message_vision(HIY "������ʿ���𳤽�����$N�����󺰣�����ʹ�ߺã�\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == fae ) {
		message_vision(HIY "������ʿ���𳤽�����$N�����󺰣�����ʹ�ߺã�\n" NOR, 
		this_player());
	}	
}
