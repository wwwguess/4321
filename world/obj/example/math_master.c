
// math_master.c

inherit NPC;

int in_ask, answer;

void create()
{
	set_name("��ľ�", ({ "math mastress", "mastress" }) );

	set("nickname", "������");
	set("gender", "Ů��");
	set("age", 31);

	set("str", 26);
	set("int", 24);

	set("force", 1600);
	set("max_force", 1600);
	set("force_factor", 5);

	set("combat_exp", 1000000);
	set("score", 9000);

	set_skill("unarmed", 100);
	set_skill("sword", 60);
	set_skill("blade", 40);
	set_skill("throwing", 40);
	set_skill("force", 100);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 60);
	set_skill("perception", 80);

	set_skill("six-chaos-sword", 80);
	set_skill("celestial", 100);
	set_skill("spring-blade", 50);
	set_skill("celestrike", 100);

	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	create_family("��а��", 16, "����");

	setup();

	carry_object("/obj/cloth")->wear();
	
	in_ask = 0;
}

void chat()
{
	int a, b;
	string oper;
	
	if( in_ask || random(100) > 10 ) return;
	a = random(100) + 1;
	b = random(100) + 1;
	switch(random(4)) {
		case 0: command("smile"); 
			answer = a + b;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "��춶��ٰ���";
			break;
		case 1: command("grin"); 
			answer = a - b;
			oper = chinese_number(a) + "��ȥ" + chinese_number(b)+ "��춶��ٰ���";
			break;
		case 2: command("giggle"); 
			answer = (a * b) % 10;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "����λ����춶��ٰ���";
			break;
		case 3: command("hehe"); 
			answer = a % b;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "��춶��ٰ���";
			break;
	}
	command("say " + oper);
	in_ask = 1;
	call_out("say_answer", 15);
}

void say_answer()
{
     command("say ����򵥶����᣿�𰸵��" + chinese_number(answer) + "��\n");
	in_ask = 0;	
}
void receive_message(string class, string msg){
	int ans;
	string who;
	
	if( !in_ask ) return;
	if( sscanf(msg, "%s˵����%d", who, ans)==2 ) {
		if( ans==answer ) {
			command("say ����ˣ�");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
		} else {
			command("say ����������");
		}
	}

}
