// mbox.c

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void create()
{
	set_name("����", ({ "mbox" }) );
	set("long",
		"����һ���������š����ŵ����䣬�����������ָ������������ʼ���\n\n"
		"mail <ĳ��>               ���Ÿ����ˡ�\n"
		"forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
		"from                      �鿴�����е��ż���\n"
		"read <�ż����>           ��\��һ���ż���\n"
		"discard <�ż����>        ����һ���ż���\n"
		"copy <�ż����>           ���ż����ݳ�¼������\n"
	);
	set("unit", "��");
	set("no_drop", 1);

	seteuid(getuid());
}

void set_owner(string id)
{
	set("id", id);
	if( !restore() ) set_temp("empty", 1);
}

void init()
{
	object ob;

	if( this_player() && environment()==this_player() ) {
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("mbox_ob", this_object());
	}

	add_action("do_mail", "mail");
	add_action("do_forward", "forward");
	add_action("do_from", "from");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
	add_action("do_copy", "copy");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("id")) )
		return DATA_DIR + "mbox/missing_mails";
	else
		return DATA_DIR + "mbox/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	if( !pointerp(mails) ) mails = ({ mail });
	else mails += ({ mail });
	save();
}

void send_mail(string rcvr, mapping mail)
{
	object ppl, ob, mbx;

	if( ppl=find_player(rcvr) )
		ob = ppl->query_temp("link_ob");
	if( !ob ) {
		ob = new(LOGIN_OB);
		ob->set("id", rcvr);
		if( !ob->restore() ) {
			write("û������˴��ڡ�\n");
			return;
		}
	}
	ob->set("new_mail", (int)ob->query("new_mail") + 1);
	ob->save();

	if( ppl ) mbx = ppl->query_temp("mbox_ob");
	if( !mbx ) {
		mbx = new(MBOX_OB);
		mbx->set_owner(rcvr);
	}

	mbx->receive_mail(mail);
	if(!ppl && mbx) destruct(mbx);
	if(!ppl && ob) destruct(ob);
}

int do_mail(string arg)
{
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("��Ҫ���Ÿ�˭��\n");

	mail = ([
		"from":	this_player()->query("name"),
		"title": "��",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("�ż����⣺");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("�ż����ݣ�(�� . ����)\n"
	"������������������������������������������������������������������������\n");
	input_to("get_mail_text", mail);
}

void get_mail_text(string str, mapping mail)
{
	if( str!="." ) {
		mail["text"] += str + "\n";
		input_to("get_mail_text", mail);
		return;
	}
	write("���Լ�Ҫ��һ�ݱ�����(y/n)��[n]");
	input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
	if( yn=="y" || yn=="Y" ) receive_mail(mail);
	send_mail(mail["to"], mail);
	write("Ok.\n");
}

int do_from()
{
	int i;

	if( !pointerp(mails) || !sizeof(mails) ) {
		write("���������Ŀǰû���κ��ż���\n");
		return 1;
	}
	write("������������ڹ��� " + sizeof(mails) + " ���ż���\n\n");
	for(i=0; i<sizeof(mails); i++)
		printf("%2d %-50s �����ˣ�%-20s\n",
			i+1, mails[i]["title"], mails[i]["from"] );
	write("\n");
	return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ����һ���ţ�\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("û�������ŵ��ż���\n");

	num --;

	printf("�ż����⣺%s\n�� �� �ˣ�%s\n\n%s\n",
		mails[num]["title"], mails[num]["from"], mails[num]["text"] );

	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ������һ���ţ�\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("û�������ŵ��ż���\n");

	num --;

	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("��Ҫ����һ����ת�ĸ����ˣ�\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("û�������ŵ��ż���\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/ת����" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}
