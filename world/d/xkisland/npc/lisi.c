// xkx.lisi.c����
// dan

inherit NPC;

string ask_me_1();  
void consider();
void create()
{
	set_name("����", ({
		"li si",
		"li",
	
	}));
	set("long",
		"����һλ��ĸߴ�������ˣ���ɫ�����������͵��ķ���ʹ�ߡ�\n"
		
	);


	set("gender", "����");
	set("attitude", "friendly");


	set("age", 40);
	
	create_family("���͵�", 2, "����");

	set("inquiry", ([
		"������" :    (: ask_me_1 :),
		
	]));

	set("zhou_count", 3);
	setup();

        carry_object("/obj/cloth/blackrobe")->wear();
}
void init()
{
    ::init();
    call_out("greeting",1,this_player());
}

void greeting(object me)
{
    remove_call_out("greeting");
    tell_object(me,@LONG
����������������������...����...
LONG);
} 
string ask_me_1()
{
	mapping fam; 
	object ob;
	
	
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��Ǹո���һ�룬��������Ҫ�ˣ� �����������࣬����ʱ�������ɡ�";

	if (  present("laba zhou", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����һ������������Ҫ�ˣ� ����̰�����У�";

	if (query("zhou_count") < 1) return "�Բ������Ѿ�������";

	ob = new("/d/xkisland/obj/zhou");
	ob->move(this_player());

	add("zhou_count", -1);

	message_vision("$N���һ���ࡣ\n",this_player());
	return "�ðɣ���ס�����ȳԡ�";

}


