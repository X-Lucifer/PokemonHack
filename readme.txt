=========== PokemonHackSourceCode Readme ===========
Author: Fuzzier
EMail:  Gauchyler@sina.com

================= Project List =====================
ProcessHandler
	���ܣ��������̣��ṩ������д�����ڴ�ռ䡣
	���ͣ���̬�⡣
	�������ޡ�

VisualBoyHandler
	���ܣ�����VisualBoyAdvance���̣��ṩ������дVBAģ���GBA�ڴ�ռ䡣
	���ͣ���̬�⡣
	������ProcessHandler

PokemonCodec
	���ܣ�
		PokemonTool���ṩ����������/Ӣ���ַ���ת��Ϊ��Ϸ�ڲ����롣
		PokemonCodec���ṩCPokemonCodec�����޸ĳ�����ڴ����ݡ�
	���ͣ���̬�⡣
	������MFC�⡣

PokemonRom
	���ܣ��ṩCPokemonRom���ROM�ļ�����VBA�ڴ��ȡROM��Ϣ��
	���ͣ���̬�⡣
	������VisualBoyHandler��MFC�⡣

PokemonMemHack
	���ܣ�
		�ṩCPokemonMemHackCore���޸ķǳ�����Ϣ������Ʒ�ȣ���
		�ṩ�û������޸ĳ�����Ϸ��
	���ͣ�EXE��ִ���ļ���
	������PokemonRom��PokemonCodec��MFC�⡣

PokemonRomViewer
	���ܣ��ṩ�û������޸ĳ���ROM��
	���ͣ�EXE��ִ���ļ���
	������PokemonRom��MFC�⡣
